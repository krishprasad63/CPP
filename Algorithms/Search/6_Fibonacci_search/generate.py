def generate_sorted_numbers(filename, count):
    with open(filename, "w") as file:
        for number in range(1, count + 1):
            file.write(f"{number} ")


filename = "sorted_numbers.txt"
count = 1000000

generate_sorted_numbers(filename, count)


