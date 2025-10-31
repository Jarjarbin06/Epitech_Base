#!/bin/bash
# builder.sh
# Build, unbuild, and rebuild subdirectories with Makefiles, with color-coded output.

# ──────────────────────────────
# Colors
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
BG_WHITE="\033[7m"
RESET="\033[0m"

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
  -h, --help       Show this help message
  -r               Rebuild all directories (overwrite existing Makefiles)
  -u, --unbuild    Unbuild all directories (remove Makefiles)
  (no option)      Build only directories without a Makefile
EOF
}

# ──────────────────────────────
# Build a directory
build_dir() {
    local dir="$1"
    local name
    name=$(truncate_dir "$dir")

    if [[ ! -e "$dir/Makefile" ]]; then
        cp /home/jarjarbin/Desktop/c/GIT/Epitech_Base/build_files/Makefile "$dir/"
        if make --no-print-directory -C "$dir" build > /dev/null 2>&1; then
            printf "${BG_WHITE}  %-*s ${RESET}${GREEN}: built${RESET}\n" "$DIR_WIDTH" "$name"
        else
            printf "${BG_WHITE}  %-*s ${RESET}${RED}: failed to build${RESET}\n" "$DIR_WIDTH" "$name"
            return
        fi
    else
        printf "${BG_WHITE}  %-*s ${RESET}${YELLOW}: already built${RESET}\n" "$DIR_WIDTH" "$name"
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
        if make --no-print-directory -C "$dir" var_ALLOW_UNBUILD=true unbuild > /dev/null 2>&1; then
            printf "${BG_WHITE}  %-*s ${RESET}${GREEN}: unbuilt${RESET}\n" "$DIR_WIDTH" "$name"
            rm -f "$dir/Makefile"
        else
            printf "${BG_WHITE}  %-*s ${RESET}${RED}: failed to unbuild${RESET}\n" "$DIR_WIDTH" "$name"
        fi
    else
        printf "${BG_WHITE}  %-*s ${RESET}${YELLOW}: no build found${RESET}\n" "$DIR_WIDTH" "$name"
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
        if make --no-print-directory -C "$dir" var_ALLOW_UNBUILD=true unbuild > /dev/null 2>&1; then
            rm -f "$dir/Makefile"
        else
            printf "${BG_WHITE}  %-*s ${RESET}${RED}: failed to unbuild${RESET}\n" "$DIR_WIDTH" "$name"
            return
        fi
    else
        printf "${BG_WHITE}  %-*s ${RESET}${YELLOW}: no build found${RESET}\n" "$DIR_WIDTH" "$name"
        return
    fi

    # Then build
    if [[ ! -e "$dir/Makefile" ]]; then
        cp /home/jarjarbin/Desktop/c/GIT/Epitech_Base/build_files/Makefile "$dir/"
        if make --no-print-directory -C "$dir" build > /dev/null 2>&1; then
            printf "${BG_WHITE}  %-*s ${RESET}${GREEN}: rebuilt${RESET}\n" "$DIR_WIDTH" "$name"
        else
            printf "${BG_WHITE}  %-*s ${RESET}${RED}: failed to rebuild${RESET}\n" "$DIR_WIDTH" "$name"
        fi
    else
        printf "${BG_WHITE}  %-*s ${RESET}${YELLOW}: already rebuilt${RESET}\n" "$DIR_WIDTH" "$name"
    fi
}

# ──────────────────────────────
# Main logic
if [[ -n "$2" ]]; then
    echo "Too many arguments. Use -h for help."
    exit 1
fi

case "$1" in
    -h|--help)
        print_help
        ;;

    -u|--unbuild)
        read -p "Are you sure yout want to delete all files in the following directories? (yes/no)
        $(dir)
        
        >>> " ALLOW_UNBUILD
        if [[ "$ALLOW_UNBUILD" = "yes" ]]; then
            echo "Unbuilding all directories..."
            for dir in */; do
                [[ -d "$dir" ]] && unbuild_dir "$dir"
            done
            echo "Unbuild complete."
        else
            echo "Unbuild cancelled."
        fi
        ;;

    -r|--rebuild)
        read -p "Are you sure yout want to delete all files in the following directories? (yes/no)
        $(dir)
        
        >>> " ALLOW_UNBUILD
        if [[ "$ALLOW_UNBUILD" = "yes" ]]; then
            echo "Rebuilding all directories..."
            for dir in */; do
                [[ -d "$dir" ]] && rebuild_dir "$dir"
            done
            echo "Rebuild complete."
        else
            echo "Rebuild cancelled."
        fi
        ;;

    "-d"|--description)
        echo "Short description:
        Builds, unbuilds, or rebuilds all subdirectories with Makefiles, showing color-coded status for each operation."
        echo -e "\n\nFull description:
        This script automates the process of building, unbuilding, and rebuilding all subdirectories that contain source code and Makefiles.
        
        It checks each subdirectory, applies a standard Makefile if one is missing, executes the build process silently, and provides color-coded feedback for each operation:
                - green indicates success, 
                - yellow indicates already built or missing build files,
                - red indicates failure.
        
        The script supports optional flags for :
                - building (-b/--build),
                - unbuilding (-u/--unbuild),
                - rebuilding (-r/--rebuild),
                - displaying help (-h/--help).
        
        Directory names are truncated for neat output, and the script ensures safe operations by prompting for confirmation before deleting any files."
        ;;

    ""|-b|--build)
        echo "Building all directories..."
        for dir in */; do
            [[ -d "$dir" ]] && build_dir "$dir"
        done
            echo "Build complete."
        ;;
    
    *)
        echo "Invalid option. Use -h for help."
        ;;
esac
