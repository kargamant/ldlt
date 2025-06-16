from scipy.linalg import ldl
import numpy as np
import argparse


def verify(matrix, ld_dec, size, acc):
    L, D = ldl(matrix)[:-1:]
    for i in range(size):
        if np.abs(D[i][i] - ld_dec[i][i]) > acc:
            print(f'D[{i}][{i}] and ld_dec[{i}][{i}] are different more than {acc}: ', D[i][i], ld_dec[i][i])
            return False
    
    for i in range(size):
        for j in range(i):
            if np.abs(L[i][j] - ld_dec[i][j]) > acc:
                print(f'L[{i}][{j}] and ld_dec[{i}][{j}] are different more than {acc}: ', L[i][j], ld_dec[i][j])
                return False

    return True

def read_matr(file):
    with open(file, 'r') as file:
        n = list(map(int, file.readline().split(' ')))[0]
        matrix = [[] for _ in range(n)]
        for arr in matrix:
            arr.extend(list(map(np.float32, file.readline().split(' ')[:-1:])))
    return n, matrix

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-if', '--ifile', action='store', type=str, help='file to read test matrix from')
    parser.add_argument('-d', '--dec', action='store', type=str, help='file to read decomposition from')
    parser.add_argument('-a', '--acc', action='store', type=float, help='accuracy to compare elements with', default=0.0001)

    args = parser.parse_args()
    if args.ifile is not None and args.dec is not None:
        size, matrix = read_matr(args.ifile)
        size, ld_dec = read_matr(args.dec)
        
        print('Correct decomposition!' if verify(matrix, ld_dec, size, args.acc) else 'Incorrect decomposition!')