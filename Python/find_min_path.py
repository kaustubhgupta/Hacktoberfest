import sys


def min_path(path):
    """
    this function recives a path of a file and will find lightest
     path from point the upper left corner to the bottom right corner
    :param path: Sting a path that contains the Matrix
    :return: the weight of the minimum path
    """

    # parses the file into a matrix
    matrix_lines = path.split('\n')
    matrix_lines = matrix_lines[:-1]
    val_matrix = [x.split() for x in matrix_lines]

    # creates a matrix of the same size just with zeros in it
    dynamic_sizes = []
    for i in range(len(val_matrix)):
        x = []
        for j in range(len(val_matrix[0])):
            x.append(0)
        dynamic_sizes.append(x)

    # go through the rows and columns
    for i in range(len(dynamic_sizes)):
        for j in range(len(dynamic_sizes[0])):

            # if we are in the first row
            if i == 0:
                # if we are in the first col and first row just use the
                # original table
                if j == 0:
                    dynamic_sizes[i][j] = int(val_matrix[i][j])
                # just use from the number from the left side and add our number
                else:
                    dynamic_sizes[i][j] = dynamic_sizes[i][j - 1]+ \
                                          int(val_matrix[i][j])
            # if we are in the col we need the value from below us
            elif j == 0:
                dynamic_sizes[i][j] =\
                    dynamic_sizes[i-1][j] + int(val_matrix[i][j])
            else:
                # gets the min between coming from the
                # left or coming from the bottom
                dynamic_sizes[i][j] = min(
                    (dynamic_sizes[i-1][j] + int(val_matrix[i][j])),
                    (dynamic_sizes[i][j-1] + int(val_matrix[i][j])))

    # returns what is in the bottom right corner
    return dynamic_sizes[len(dynamic_sizes)-1][len(dynamic_sizes[0]) - 1]


if __name__ == '__main__':
    v = open(sys.argv[1]).read()
    print(min_path(v))
