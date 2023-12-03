
import re

def calculate_ex1(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    sum = 0
    for line in lines:
        dig = []
        for ch in line:
            if ch.isdigit():
                dig.append(ch)
        sum += int(dig[0])*10
        sum += int(dig[-1])

    return sum

def calculate_ex2(input_file_name):
    numbers_alpha = {"one" : '1', "two": '2', "three": '3', 
                    "four": '4', "five": '5', "six" : '6', 
                    "seven" : '7', "eight" : '8', "nine" : '9', 
                    "1":"1","2": "2","3":"3","4":"4", "5":"5","6": "6","7":"7","8":"8", "9":"9"}
    f = open(input_file_name, "r")
    lines = f.readlines()
    sum = 0
    for line in lines:
        dig = re.findall("(?=(\d|one|two|three|four|five|six|seven|eight|nine))", line)       
        dig_1_10 = numbers_alpha[dig[0]]
        dig_1 = numbers_alpha[dig[-1]]
        sum += int(dig_1_10)*10
        sum += int(dig_1)

    return sum

if __name__ == "__main__":
    res1 = calculate_ex1("input.txt")
    res2_sample = calculate_ex2("input_sample_ex2.txt")
    res2 = calculate_ex2("input.txt")
    print(f"ex1: {res1}, ex2 sample: {res2_sample} res2: {res2}")
