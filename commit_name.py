## commit_name ##
## by JARJARBIN'S STUDIO ##

import os, time

commit_lines = {
    "ADD" : [],
    "FIX" : [],
    "UPDATE" : [],
    "REMOVE" : []
    }
commit_color = {
    "ADD" : "\033[92m",
    "FIX" : "\033[94m",
    "UPDATE" : "\033[96m",
    "REMOVE" : "\033[91m"
    }
commit_title = ""
commit_description = ""

def clear() -> None :
    """Clears the terminal screen."""
    os.system('clear')

def place(*, category : str | None = None) -> None :
    """Prints the current state of commit_lines."""
    if category :
        if not (commit_lines[category] in [[''], []]) :
            print(f"{commit_color[category]}{category}\033[0m :")
            for file in commit_lines[category] :
                if file != '' :
                    print(f"  - {commit_color[category]}{file}\033[0m")
        return
    print(f"{commit_title}\n")
    for category in commit_lines :
        place(category = category)

def fill() -> None :
    """Fills the commit_lines dictionary with file paths from user input (if file paths exists)."""
    for action in commit_lines :
        file = " "
        while file != "":
            clear()
            place(category = action)
            file = input(f"\nnew {commit_color[action]}{action}\033[0m :\n    >>> ")
            if os.path.isfile(f"../{file}") :
                commit_lines[action].append(file)
            elif file != "" :
                print(f'\n\033[31m[ERROR] -> "{file}" is not a valid file path.\033[0m')
                time.sleep(2)

def get_title() -> None :
    """Generates the commit title based on the first non-empty action in commit_lines and user input."""
    global commit_title
    commit_title_action = ""
    for action in commit_lines :
        print(commit_lines[action])
        if commit_lines[action] != [] :
            commit_title_action = action
            break
    clear()
    commit_title = f"[{commit_title_action}] {input(f"TITLE : [{commit_color[commit_title_action]}{commit_title_action}\033[0m] :\n    >>> ")}"

def get_description() -> None :
    """Generates the commit description based on the contents of commit_lines."""
    global commit_description
    for key in commit_lines :
        if commit_lines[key] != [''] :
            for file in commit_lines[key] :
                if file != '' :
                    commit_description += f"\n[{key}] {file}"

def copy_commit_name() -> None :
    """Generates the commit title and description, copies them to clipboard."""
    global commit_lines, commit_title, commit_description
    fill()
    get_title()
    get_description()
    os.system(f'echo "{commit_title}\n{commit_description}" | clipboard')
    clear()

try :
    copy_commit_name()
except KeyError :
    clear()
    print("\033[31m[ERROR] -> An unexpected error occurred. Please try again.\033[0m")
else :
    print("\033[92m[SUCCESS] -> Commit name copied to clipboard!\033[0m\n")
    place()