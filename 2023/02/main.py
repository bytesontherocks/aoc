import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    possible_game_ids = []
    sum_ex2 = 0
    for line in lines:
        id = int(re.findall(r'\d+',line[:line.find(":")])[0])
        red_pat = re.compile(r'\b\d+ red\b').findall(line)
        blue_pat = re.compile(r'\b\d+ blue\b').findall(line)
        green_pat = re.compile(r'\b\d+ green\b').findall(line)

        valid_game_id = True        
        min_r=0
        for r in red_pat:
            r_num = int(re.findall(r'\d+', r)[0])
            if r_num > min_r:
                min_r = r_num
            if r_num > 12:
                valid_game_id = False
        min_b=0
        for b in blue_pat:
            b_num = int(re.findall(r'\d+', b)[0])
            if b_num > min_b:
                min_b = b_num
            if b_num > 14:
                valid_game_id = False
        min_g = 0
        for g in green_pat:
            g_num = int(re.findall(r'\d+', g)[0])
            if g_num > min_g:
                min_g = g_num
            if g_num > 13:
                valid_game_id = False
        if valid_game_id == True:
            possible_game_ids.append(id)
        power = min_r * min_b * min_g
        #print(f"min_r: {min_r}, min_b: {min_b}, min_g: {min_g} ")
        sum_ex2 += power
        #print (power)
    sum_ex1=0
    for p in possible_game_ids:
        sum_ex1 += p
    return sum_ex1, sum_ex2
    
if __name__ == "__main__":
    res_sample = calculate_ex("input_sample_ex.txt")
    res = calculate_ex("input.txt")
    print(f"ex sample: {res_sample}, ex: {res}")