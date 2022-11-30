
        
def calculate_ex1(input_file_name):
    f = open(input_file_name, "r")
    return f.readlines()
    


if __name__ == "__main__":
    lines = calculate_ex1("input.txt")
    count = 0
    # Strips the newline character
    #for line in lines:
    for line in lines[0:len(lines)-1]:
        count += 1
        print("Line{}: {}".format(count, line.strip()))