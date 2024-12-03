
import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    l = []
    r = []
    for line in lines:
        ln, rn = line.split()
        l.append(int(ln))
        r.append(int(rn))
    l.sort()
    r.sort()
    c = 0
    e1 = 0
    e2 = 0
    for n in l:
        d = abs(r[c] - l[c])
        e2 += l[c] * r.count(l[c])
        e1 += d
        c += 1

    return e1, e2


if __name__ == "__main__":
    ex_res_1, ex_res_2 = calculate_ex("input.txt")