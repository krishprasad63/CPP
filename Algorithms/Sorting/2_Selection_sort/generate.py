import random

def generate_random_numbers(filename, count, min_val=1, max_val=100000):
    with open(filename, "w") as file:
        for _ in range(count):
            number = random.randint(min_val, max_val)
            file.write(f"{number} ")

filename = "numbers.txt"
count = 100000

generate_random_numbers(filename, count)
