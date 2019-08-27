# Exercise: Fill 2*N space with 1x1, 2x1 blocks

# Program parameters
AREA_WIDTH = 2
AREA_HEIGHT = int(input())

# Block types

# [x shift, y shift, type]
_type_id = '●'
_BLOCK_TYPES_1x1 = [
    [[0, 0, _type_id]]
]

_type_id = '⇿'
_BLOCK_TYPES_2x1 = [
    [[0, 0, _type_id], [0, +1, _type_id]],
    [[0, 0, _type_id], [0, -1, _type_id]],
]
_type_id = '⇳'
_BLOCK_TYPES_1x2 = [
    [[0, 0, _type_id], [+1, 0, _type_id]],
    [[0, 0, _type_id], [-1, 0, _type_id]],
]

BLOCK_TYPES = _BLOCK_TYPES_1x2 + _BLOCK_TYPES_2x1 + _BLOCK_TYPES_1x1

# The board (space to fill with blocks)
class Board:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.empty()
    def empty(self):
        # initializes a hidden empty list of size width*height
        self._value = []
        self.remaining = self.width * self.height
        for x in range(self.width):
            row = []
            for y in range(self.height):
                row.append(0)
            self._value.append(row)
    def is_free(self, x, y):
        if x not in range(self.width):
            return False
        if y not in range(self.height):
            return False
        return self._value[x][y] == 0
    def free(self, x, y):
        if self._value[x][y] == 0:
            raise Exception("Area already free")
        self._value[x][y] = 0
        self.remaining += 1
    def reserve(self, x, y, type):
        if self._value[x][y] != 0:
            raise Exception("Area already filled")
        self._value[x][y] = type
        self.remaining -= 1
    def list_free(self):
        results = []
        for x in range(self.width):
            for y in range(self.height):
                if self.is_free(x, y):
                    results.append([x, y])
        return results
    def print(self):
        result = ""
        for x in range(self.width):
            for y in range(self.height):
                result += str(self._value[x][y]) + " "
            result += "\n"
        return result

# The worker

def worker(board, results = []):
    if board.remaining == 0:
        solution_hash = board.print()
        if solution_hash in results:
            return 0
        results.append(solution_hash)
#        print(solution_hash) # DEBUG
        return 1
    solutions = 0
    
    for free_position in board.list_free():

        x_initial, y_initial = free_position

        for block_type in BLOCK_TYPES:
        # Check if the block can be placed

            # optimization: skip if not enough space
            if board.remaining < len(block_type):
                continue
            is_block_type_available = True
            for required_field in block_type:
                x_shift, y_shift, _ = required_field
                x, y = x_initial + x_shift, y_initial + y_shift
                if not board.is_free(x, y):
                    is_block_type_available = False
                    break # Kirúgnak emiatt :( - Mező

            if not is_block_type_available:
                continue
            
            # Place the block
            for required_field in block_type:
                x_shift, y_shift, block_type_id = required_field
                x, y = x_initial + x_shift, y_initial + y_shift
                board.reserve(x, y, block_type_id)
            
            # Recursion
            solutions += worker(board)

            # Remove the block
            for required_field in block_type:
                x_shift, y_shift, _ = required_field
                x, y = x_initial + x_shift, y_initial + y_shift
                board.free(x, y)

    return solutions


num_solutions = worker(Board(AREA_WIDTH, AREA_HEIGHT))

print(num_solutions)
