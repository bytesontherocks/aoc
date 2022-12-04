
def calculateScoreEx1(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    score = 0
    for line in lines:
        line = line.strip('\n')
        line = line.split(',', 1)
        s1 = line[0].split('-', 1)
        s2 = line[1].split('-', 1)
        s1_ext = list(range(int(s1[0]),int(s1[len(s1)-1])+1))
        s2_ext = list(range(int(s2[0]),int(s2[len(s2)-1])+1))

        if set(s1_ext).issubset(s2_ext) or set(s2_ext).issubset(s1_ext):
            score += 1  

    return score

def calculateScoreEx2(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    score = 0
    for line in lines:
        line = line.strip('\n')
        line = line.split(',', 1)
        s1 = line[0].split('-', 1)
        s2 = line[1].split('-', 1)
        s1_ext = list(range(int(s1[0]),int(s1[len(s1)-1])+1))
        s2_ext = list(range(int(s2[0]),int(s2[len(s2)-1])+1))

        if set(s1_ext).intersection(s2_ext):
            score += 1  

    return score

        
if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")