#!/bin/bash
# builder.sh
# by Jarjarbin's studio (with help of ChatGPT)
# Build, unbuild, and rebuild subdirectories with Makefiles, with color-coded output.

# ──────────────────────────────
# Colors
RESET="\033[0m"
WHITE="\033[97m"
BLACK="\033[2m"
DARK="\033[30m"
BG_WHITE="\033[7m"
BG_GREEN="\033[42m"
BG_RED="\033[41m"
BG_YELLOW="\033[43m"

DIR_WIDTH=50  # maximum width for directory names

# ──────────────────────────────
# Helper: truncate directory name if too long
truncate_dir() {
    local dir="$1"
    if (( ${#dir} > DIR_WIDTH )); then
        printf "%s..." "${dir:0:DIR_WIDTH-3}"
    else
        printf "%s" "$dir"
    fi
}

# ──────────────────────────────
# Print usage
print_help() {
    cat <<EOF
Usage: build_all.sh [option]
Options:
  -h, --help							    Show this help message
  -d, --description				    Show a complete description of the program
  -r, --rebuild						    Rebuild all directories (overwrite existing Makefiles)
  -u, --unbuild               Unbuild all directories (remove Makefiles)
  (no option), -b, --build    Build only directories without a Makefile
EOF
}

# ──────────────────────────────
# Build a directory
build_dir() {
    local dir="$1"
    local name
    name=$(truncate_dir "$dir")

    if [[ ! -e "$dir/Makefile" ]]; then
        cp -f /home/jarjarbin/Desktop/c/Epitech_Base/Makefile "$dir/"
        if make --no-print-directory -C "$dir" setup-build > /dev/null 2>&1; then
            printf "${BG_WHITE} ${RESET}${WHITE} %-*s : ${RESET}${DARK}${BG_GREEN}             built ${RESET}\n" "$DIR_WIDTH" "$name"
        else
            printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_RED}   failed to build ${RESET}\n" "$DIR_WIDTH" "$name"
            return
        fi
    else
        printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_YELLOW}     already built ${RESET}\n" "$DIR_WIDTH" "$name"
        return
    fi
}

# ──────────────────────────────
# Unbuild a directory
unbuild_dir() {
    local dir="$1"
    local name
    name=$(truncate_dir "$dir")

    if [[ -e "$dir/Makefile" ]]; then
        if make --no-print-directory -C "$dir" ALLOW_UNBUILD=true unbuild > /dev/null 2>&1; then
            printf "${BG_WHITE} ${RESET}${WHITE} %-*s : ${RESET}${DARK}${BG_GREEN}           unbuilt ${RESET}\n" "$DIR_WIDTH" "$name"
            rm -f "$dir/Makefile"
        else
            printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_RED} failed to unbuild ${RESET}\n" "$DIR_WIDTH" "$name"
        fi
    else
        printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_YELLOW}    no build found ${RESET}\n" "$DIR_WIDTH" "$name"
    fi
}

# ──────────────────────────────
# Rebuild a directory
rebuild_dir() {
    local dir="$1"
    local name
    name=$(truncate_dir "$dir")

    # First unbuild
    if [[ -e "$dir/Makefile" ]]; then
        if make --no-print-directory -C "$dir" ALLOW_UNBUILD=true unbuild > /dev/null 2>&1; then
            rm -f "$dir/Makefile"
        else
            printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_RED} failed to unbuild ${RESET}\n" "$DIR_WIDTH" "$name"
            return
        fi
    else
        printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_YELLOW}    no build found ${RESET}\n" "$DIR_WIDTH" "$name"
        return
    fi

    # Then build
    if [[ ! -e "$dir/Makefile" ]]; then
        cp -f /home/jarjarbin/Desktop/c/Epitech_Base/Makefile "$dir/"
        if make --no-print-directory -C "$dir" setup-build > /dev/null 2>&1; then
            printf "${BG_WHITE} ${RESET}${WHITE} %-*s : ${RESET}${DARK}${BG_GREEN}           rebuilt ${RESET}\n" "$DIR_WIDTH" "$name"
        else
            printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_RED} failed to rebuild ${RESET}\n" "$DIR_WIDTH" "$name"
        fi
    else
        printf "${BLACK}  %-*s : ${RESET}${DARK}${BG_YELLOW}   already rebuild ${RESET}\n" "$DIR_WIDTH" "$name"
    fi
}

# ──────────────────────────────
# Main logic
if [[ -n "$2" ]]; then
    printf "\n${BG_WHITE}Too many arguments. Use -h for help.${RESET}\n"
    exit 1
fi

case "$1" in
    -h|--help)
        print_help
        ;;

    -u|--unbuild)
        echo -ne "Are you sure yout want to delete all files in the following directories? (yes/no)\n\n$(dir)\n\n    >>> "
        read -p "" ALLOW_UNBUILD
        if [[ "$ALLOW_UNBUILD" = "yes" ]]; then
            printf "\n${BG_WHITE}Unbuilding all directories...${RESET}\n\n"
            for dir in */; do
                [[ -d "$dir" ]] && unbuild_dir "$dir"
            done
            printf "\n${BG_WHITE}Unbuild complete.${RESET}\n"
        else
            printf "\n${BG_WHITE}Unbuild cancelled.${RESET}\n"
        fi
        ;;

    -r|--rebuild)
        echo -ne "Are you sure yout want to delete all files in the following directories? (yes/no)\n\n$(dir)\n\n    >>> "
        read -p "" ALLOW_REBUILD
        if [[ "$ALLOW_REBUILD" = "yes" ]]; then
            printf "\n${BG_WHITE}Rebuilding all directories...${RESET}\n\n"
            for dir in */; do
                [[ -d "$dir" ]] && rebuild_dir "$dir"
            done
            printf "\n${BG_WHITE}Rebuild complete.${RESET}\n"
        else
            printf "\n${BG_WHITE}Rebuild cancelled${RESET}\n"
        fi
        ;;

    "-d"|--description)
        echo "Builds, unbuilds, or rebuilds all subdirectories with Makefiles, showing color-coded status for each operation."
        echo -e "\n\nFull description:
        This script automates the process of building, unbuilding, and rebuilding all subdirectories that contain source code and Makefiles.
        
        It checks each subdirectory, applies a standard Makefile if one is missing, executes the build process silently, and provides color-coded feedback for each operation:
                - green indicates success, 
                - yellow indicates already built or missing build files,
                - red indicates failure.
        
        The script supports optional flags for :
                - building ((no option)/-b/--build),
                - unbuilding (-u/--unbuild),
                - rebuilding (-r/--rebuild),
                - displaying help (-h/--help).
        
        Directory names are truncated for neat output, and the script ensures safe operations by prompting for confirmation before deleting any files."
        ;;

    ""|-b|--build)
        printf "${BG_WHITE}Building all directories...${RESET}\n\n"
        for dir in */; do
            [[ -d "$dir" ]] && build_dir "$dir"
        done
            printf "\n${BG_WHITE}Build complete.${RESET}\n"
        ;;
    
    *)
        if [ -d "$1" ]; then
            build_dir "$1"
        else
            printf "\n${BG_WHITE}The specified directory does not exist or is not a folder.${RESET}\n"
        fi
        ;;
esac
