
import re

def check_level_rm_1_elem(level : list) -> int:
    # brute force
    for i in range(len(level)):
        nnl= level[:i]+level[i+1:]
        s,d=is_level_safe(nnl)
        if s:
            return 1
    return 0

def is_level_safe(level : list) -> int:
    d=[]
    last = level[0]
    for i in level[1:]:
        d.append(i - last)
        last = i
    is_safe = 0
    if all(num in range(1,4) for num in d):
        is_safe=1
    elif all(num < 0 and num > -4 for num in d):
       is_safe=1
    return is_safe,d

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    
    e1=0
    e2=0
    counter=0
    for l in lines:    
        n = l.split()
        n_l = [int(i) for i in n]
        s,d=is_level_safe(n_l)
        if s:
            e1+=1
            e2+=1
        else:
            # brute force
            #e2 += check_level_rm_1_elem(n_l)

            # slighlty more performant(?, haven't checked actually) than brute force
            # instead of checking each single level, do some triage and just apply brute
            # force to them              
            
            # there cases where there are 2 False's but removing 1 element fixes the value 
            MAX_ELEM_TO_REMOVE = 1
            MAX_WRONG_ELEM = MAX_ELEM_TO_REMOVE + 1
            if  [num in range (1,4) for num in d].count(False) <= MAX_WRONG_ELEM or \
                [num < 0 and num > -4 for num in d].count(False) <= MAX_WRONG_ELEM:

                for i in range(len(n_l)):
                    nnl= n_l[:i]+n_l[i+1:] # create a new list to re-evaluate
                    s,d=is_level_safe(nnl)
                    if s:
                        e2+=1
                        break
    
    print(f"ex1 result: {e1}, ex2 result: {e2}")
    return e1, e2

if __name__ == "__main__":
    ex_res_1, ex_res_2 = calculate_ex("input.txt")
    