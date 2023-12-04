import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    res = 0
    for line in lines:
        line_nums = line.split(":")[1]
        winners = [int(i) for i in re.findall("\d+",line_nums.split("|")[0])]
        candidates = [int(i) for i in re.findall("\d+",line_nums.split("|")[1])]
        print(f"winners: {winners}")
        print(f"candidates: {candidates}")
        sum = []
        points = 1
        for c in candidates:
            loc_sum = 0
            for w in winners:
                if c == w:
                    loc_sum += points
                    points *= 2
            sum.append(loc_sum)
        res += max(sum)       
    
    return res, 0
    
if __name__ == "__main__":
    res_sample = calculate_ex("input_sample_ex.txt")
    res = calculate_ex("input.txt")
    print(f"ex sample: {res_sample}, ex: {res}")