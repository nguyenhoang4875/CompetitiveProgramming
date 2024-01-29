import os
import sys
from os.path import exists

# CONFIG
BASE_NAME   = ""
EXT         = ""
TEST_QTY    = 1
FILE_PATH   = ""
FOLDER_PATH = ""


def for_cpp():
    pass


def for_py():
    for i in range(TEST_QTY):
        file_name = BASE_NAME + f"{i:01d}"
        file_path = f'{FOLDER_PATH}/{file_name}.in'
        if file_path[0] == '/':
            file_path = file_path[1:]
        if exists(file_path):
            print(f"[{file_path}] already exists")
        else:
            os.system(f"py {FILE_PATH} > {file_path}")
            print(f"[{file_path}] has been generated")

    print("OK")


if __name__ == "__main__":
    # Read param
    if len(sys.argv) >= 2:
        tmp = os.path.basename(sys.argv[3]).split('.')
        if len(tmp) != 2:
            print("ERROR: Invalid file_name, file_name must be cpp or py, example: solution.cpp solution.py")
            exit()
        FILE_PATH = sys.argv[3]
        BASE_NAME = sys.argv[1]
        if BASE_NAME == 'BLANK':
            BASE_NAME = ''
        EXT = tmp[1]
        TEST_QTY = int(sys.argv[2])
        FOLDER_PATH = os.path.dirname(sys.argv[3])
    else:
        print(f'ERROR: Invalid syntax, syntax: py gen_in.py <base_name> <number_of_testcase> <file_path>')
        exit()

    print(EXT)
    if EXT == 'cpp' and exists(FILE_PATH):
        for_cpp()
    elif EXT == 'py' and exists(FILE_PATH):
        for_py()
    else:
        print(f"ERROR: Not found {FILE_PATH}")
