
def calculateScoreEx1(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    score = 0
    for line in lines:
        line = line.strip('\n')

        #split line into 2 strings
        num_ch_ln = len(line)
        s1 = line[0:int((num_ch_ln/2))]
        s2 = line[int(num_ch_ln/2):int( num_ch_ln)]

        # print(s1)
        # print(s2)
        # print(line)

        ch_common = ''.join(set(s1).intersection(s2))

        str_common = ch_common + '\n'    
        print(ch_common)
        print(ord(str_common[0]))
        loc_score = 0
        if ch_common.islower():
            loc_score = (ord(str_common[0]) - 96)
        else:   
            str_common.lower()
            loc_score = (ord(str_common[0]) - 64) + 26

        print (loc_score)
        score += loc_score

    return score


def calculateScoreEx2(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    ix_line = 0
    score = 0

    while ix_line < len(lines):
        s1 = lines[ix_line].strip('\n')
        s2 = lines[ix_line + 1].strip('\n')
        s3 = lines[ix_line + 2].strip('\n')
        s1_2_common = ''.join(set(s1).intersection(s2))
        s1_2_3_common = ''.join(set(s1_2_common).intersection(s3))
        print(s1_2_3_common)

        str_common = s1_2_3_common + '\n'    
        print(s1_2_3_common)
        print(ord(str_common[0]))
        loc_score = 0
        if s1_2_3_common.islower():
            loc_score = (ord(str_common[0]) - 96)
        else:   
            str_common.lower()
            loc_score = (ord(str_common[0]) - 64) + 26

        print (loc_score)
        score += loc_score
        ix_line += 3

    return score

        
if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")