


def getList(lines):
    reg = []
    x=1
    reg.append(x)
    for ln in lines:
        ln = ln.split()

        if ln[0] == "addx":
            reg.append(x)
            reg.append(x)
            x += int(ln[1])
        else:
            reg.append(x)
    return reg

def calculateScoreEx1(input_file_name):    

    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        reg = getList(lines)

    th=[20,60,100,140,180,220]
    sum=0
    for val in th:
        sum+=reg[val]*val

    print(sum)
        
    return 0
# cycle cmd     Val
# 0               1
# 1     noop      1
# 2     addx 3    1
# 3               1
# 4     addx -5   4


def calculateScoreEx2(input_file_name):    
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        reg = getList(lines)
        print(reg)
        print(f"len_reg{len(reg)}")
        crt = []

        for ix in range(0,6):
            crt_ln=''        
            for crt_pos in range(0, 40):
                cycle = 1+crt_pos + ix*40
                rex_x = reg[cycle] - 1
                if crt_pos < rex_x+3 and crt_pos >=rex_x:
                    crt_ln+='#'
                else:
                    crt_ln+='.'

            crt.append(crt_ln)

        for c in crt:
            print(c)

    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")