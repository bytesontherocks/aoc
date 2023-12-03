import re

def is_included(c_ix, digit_len, lines, line_ix):

    d_ix_start = max(0, c_ix - 1)
    d_ix_end = min(c_ix + digit_len, len(lines[line_ix]) - 2) + 1
    l_ix_start = max(0, line_ix - 1)
    l_ix_end = min(line_ix + 1, len(lines)-1)
 
    l_0 = lines[l_ix_start].strip()[d_ix_start:d_ix_end]
    l_1 = lines[line_ix].strip()[d_ix_start:d_ix_end]
    l_2 = lines[l_ix_end].strip()[d_ix_start:d_ix_end]  
    
    # print(f"d_ix_start: {d_ix_start}, d_ix_end: {d_ix_end}")
    # print(f"l_ix_start: {l_ix_start}, l_ix_end: {l_ix_end}")
    # print(f"l_0: {l_0}, l_1: {l_1}, l_2: {l_2}")

    pattern = re.compile("[-$&+%_,'\":;~=/\*?@#]+") 
    if pattern.search(l_0) != None or pattern.search(l_1) != None or pattern.search(l_2) != None:

        print("Special character found")
        return True

    return False

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    sum = 0
    line_ix = 0
    while line_ix < len(lines):
        current_line = lines[line_ix]
        nums = re.findall(r'\d+', current_line)
        for n in nums:
            d_ix = lines[line_ix].find(n)
            if is_included(d_ix, len(n), lines, line_ix) == True:
                print(n)
                sum += int(n)
        line_ix += 1
    return sum, 0
    
if __name__ == "__main__":
    res_sample = calculate_ex("input_sample_ex.txt")
    res = calculate_ex("input.txt")
    print(f"ex sample: {res_sample}, ex: {res}")