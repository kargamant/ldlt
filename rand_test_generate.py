import numpy as np
import argparse

def generate_random_spd_matrix(size, lambda_=0.1):
    A = np.random.randn(size, size)
    
    B = A.T @ A
    
    B += lambda_ * np.eye(size)
    
    return B

def verify(matrix):
    try:
        np.linalg.cholesky(matrix)
        return True
    except np.linalg.LinAlgError:
        return False

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', action='store', help='size of matrix', type=int)
    parser.add_argument('-f', '--file', action='store', help='file to offload generated matrix', type=str)
    
    args = parser.parse_args()
    if args.n:
        matrix = generate_random_spd_matrix(args.n)

        if args.file is not None:
            with open(args.file, 'w') as file:
                file.write(f'{args.n} {args.n}\n')
                for line in matrix:
                    for item in line:
                        file.write(f'{item} ')
                    file.write('\n')
            print(f'matrix was saved to {args.file}')
        else:
            print(matrix)
            # print('verified!' if verify(matrix) else 'not verified')
