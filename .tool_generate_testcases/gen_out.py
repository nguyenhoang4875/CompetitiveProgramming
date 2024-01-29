import os
import sys
from os.path import exists

# CONFIG
BASE_NAME   = ""
EXT         = ""
TEST_QTY    = 1
FILE_PATH   = ""
FOLDER_PATH = ""


def get_param(i):
    file_name = BASE_NAME + f"{i:01d}"
    file_path = f'{FOLDER_PATH}/{file_name}.in'
    file_path_out = f'{FOLDER_PATH}/{file_name}.out'
    if file_path[0] == '/':
        file_path = file_path[1:]
    if file_path_out[0] == '/':
        file_path_out = file_path_out[1:]
    return file_name, file_path, file_path_out


def for_cpp():
    os.system(f"g++ -std=c++11 {FILE_PATH} -o file_solution")
    for i in range(TEST_QTY):
        file_name, file_path, file_path_out = get_param(i)
        if not exists(file_path):
            print(f"[{file_path}] not exists")
            print(f"[{file_name}.in] not found")
            print("FAILED")
            exit(0)
        os.system(f"file_solution.exe < {file_path} > {file_path_out}")
        print(f"[{file_name}.out] has been generated")

    print("OK")


def for_py():
    for i in range(TEST_QTY):
        file_name = BASE_NAME + f"{i:01d}"
        file_path = f'{FOLDER_PATH}/{file_name}.in'
        file_path_out = f'{FOLDER_PATH}/{file_name}.out'
        if file_path[0] == '/':
            file_path = file_path[1:]
        if file_path_out[0] == '/':
            file_path_out = file_path_out[1:]
        if not exists(file_path):
            print(f"[{file_path}] not exists")
        else:
            os.system(f"py {FILE_PATH} < {file_path} > {file_path_out}")
            print(f"[{file_path_out}] has been generated")

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
        print(f'ERROR: Invalid syntax, syntax: py gen_out.py <base_name> <number_of_testcase> <file_path>')
        exit()

    print(EXT)
    if EXT == 'cpp' and exists(FILE_PATH):
        for_cpp()
    elif EXT == 'py' and exists(FILE_PATH):
        for_py()
    else:
        print(f"ERROR: Not found {FILE_PATH}")
