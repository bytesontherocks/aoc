
import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    
    e1 = 0
    for l in lines:
        
        print("////")
        n = l.split()
        n_l = [int(i) for i in n]
        min_nl = min(n_l) - 1
        max_nl = max(n_l) + 1
        min_s = True
        max_s = True
        dampener_applied_min = False
        dampener_applied_max = False   
    
        for i in n_l:
            d = abs(min_nl - i)
            if i > min_nl and d <= 3:
                min_nl = i
            else:                
                if  d <= 1  and dampener_applied_min == False:
                    min_nl = i
                    dampener_applied_min = True
                    print("damped min")
                else:
                    min_s = False

            d = abs(i - max_nl)
            if i < max_nl and d <= 3:
                max_nl = i
            else:                
                if  d <= 1  and dampener_applied_max == False:
                    max_nl = i
                    dampener_applied_max = True
                    print("damped max")
                else:
                    max_s = False

        safe = False
        if min_s or max_s:
            safe = True
            e1 +=1
            print(n_l)
            print("////")

        
        print(safe)

    e2 = 0

    return e1, e2


if __name__ == "__main__":
    ex_res_1, ex_res_2 = calculate_ex("input.txt")