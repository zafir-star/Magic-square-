def generate_magic_square(n):
    # Create an n x n matrix filled with 0
    magic_square = [[0 for _ in range(n)] for _ in range(n)]

    # Starting position
    row = 0
    col = n // 2

    for num in range(1, n * n + 1):
        magic_square[row][col] = num

        # Calculate next position
        next_row = (row - 1) % n
        next_col = (col + 1) % n

        # If the cell is already occupied, move down instead
        if magic_square[next_row][next_col] != 0:
            row = (row + 1) % n
        else:
            row = next_row
            col = next_col

    return magic_square


# Main program
n = int(input("Enter an odd number: "))

if n % 2 == 0:
    print("Magic square can only be generated for odd numbers.")
else:
    square = generate_magic_square(n)

    print("\nMagic Square:")
    for row in square:
        for value in row:
            print(f"{value:3}", end=" ")
        print()