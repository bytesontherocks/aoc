
import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    
    e1 = 0
    for l in lines:
    
        n = l.split()
        n_l = [int(i) for i in n]

        l_i = n_l.copy()
        l_i.sort()
        l_d = n_l.copy()
        l_d.sort(reverse=True)

        if n_l != l_i and n_l != l_d:
            continue
        
        last = n_l[0]
        d = []
        for i in n_l[1:]:
            delta = abs(i  - last)
            d.append(delta in range(1, 4))
            last = i
        if all(d):
            e1 += 1
 

    e2 = e1

    for l in lines:
    
        n = l.split()
        n_l = [int(i) for i in n]

        d=[]
        last = n_l[0]
        for i in n_l[1:]:
            d.append(i - last)
            last = i
        # if all(num in range (1,4) for num in d):
        #     e1+=1
        # if all(num < 0 and num > -4 for num in d):
        #     e1+=1

        a = [num in range (1,4) for num in d]
        b = [num < 0 and num > -4 for num in d]

        if a.count(False) == 1:
            a_val = a.index(False)
            print (f"a_val {a_val}")
            if a_val == 0 or a_val == -1:
                e2+=1

        if b.count(False) == 1:
            b_val = b[b.index(False)]
            print (f"b_val {b_val}")
            if b_val == 0 or b_val == -1:
                e2+=1

        print(n_l)
        print(d)
        print(a)
        print(b)


    return e1, e2


if __name__ == "__main__":
    ex_res_1, ex_res_2 = calculate_ex("input.txt")