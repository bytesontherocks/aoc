def getNextLine(lines, ix):
    return lines[ix].split(), ix + 1
    return 0

def getDirectorySize(tree, dir_id):
    dir=tree[dir_id]
    dir_sz=0
    for d in dir:
        if d.isalpha():
            dir_sz += getDirectorySize(tree, d)
        else:
            dir_sz += d
    
    return dir_sz
    
def getDirectoriesSize(tree):
    dir = tree['/']
    list_d_sz=[]
    dir_sz=0
    for d in dir:
        if d.isalpha():
            dir_sz += getDirectorySize(tree, d)
        else:
            dir_sz += d
        list_d_sz.append(dir_sz)
        
    return list_d_sz


def calculateScoreEx1(input_file_name):
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        tree = {} # contains all the directories
        ln_ix=0 
        while ln_ix < len(lines):     
            ln, ln_ix = getNextLine(lines, ln_ix)
            if ln[1] == "ls":
                dir_name = lines[ln_ix - 2].split()[2]
                ln, ln_ix = getNextLine(lines, ln_ix)
                dir = []
                acc_size = 0
                while ln[0] != "$" and ln_ix < len(lines):
                    if ln[0] == "dir":
                        dir.append(ln[1])
                    elif ln[0].isdigit():
                        acc_size += int(ln[0])

                    ln, ln_ix = getNextLine(lines, ln_ix)

                dir.append(acc_size)
                tree[dir_name]= dir

        print(f"tree: {tree}")

        sz = getDirectoriesSize(tree)
        # dir_size=[]
        # for dir in tree:
        #     dir_size.append(getDirectorySize(tree, "/"))

    return 0

def calculateScoreEx2(input_file_name):    
    f = open(input_file_name, "r")
    lines = f.readlines()  
    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")