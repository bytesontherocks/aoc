
import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    
    e1 = 0
    for l in lines:    
        n = l.split()
        n_l = [int(i) for i in n]
        d=[]
        last = n_l[0]
        for i in n_l[1:]:
            d.append(i - last)
            last = i
        if all(num in range (1,4) for num in d):
            e1+=1
        if all(num < 0 and num > -4 for num in d):
            e1+=1 

    e2 = e1
    for l in lines:    
        n = l.split()
        n_l = [int(i) for i in n]
        d=[]
        last = n_l[0]
        for i in n_l[1:]:
            d.append(i - last)
            last = i

        a=[]
        b=[]
        if all(num >= -1 and num < 4 for num in d):
            if (d.count(-1) + d.count(0)) == 1:
                
                if not [1, -1, 1] in (d[i:i+3] for i in range(len(d) - 2)):
                  e2+=1  
                print(n_l)
                print(d)
        #a = [num >= -1 and num < 4 for num in d]
        if all(num <= 1 and num > -4 for num in d):
             if (d.count(1) + d.count(0)) == 1:
                if not [1, -1, -1] in (d[i:i+3] for i in range(len(d) - 2)):
                  e2+=1  
                
                print(n_l)
                print(d)
    


    return e1, e2


if __name__ == "__main__":
    ex_res_1, ex_res_2 = calculate_ex("input.txt")