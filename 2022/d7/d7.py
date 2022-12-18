class Dir:
    parent = 0
    size = 0
    def __init__(self, id, parent):
        self.id=id
        self.parent=parent
        self.nested_dirs = []

    def getParent(self):
        return self.parent
    def getSize(self, dirs):
        sz = self.size
        for d in self.nested_dirs:
            sz+=dirs[d].getSize(dirs)
        return sz
    def accSize(self, size):
        self.size+=size
    def addDir(self, dir):
        self.nested_dirs.append(dir)

def getDirs(input_file_name):
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        ln_ix=0 
        dirs=[]
        dirs.append(Dir('/', 0))#create root
        dirs_ix = 0
        current_dir = dirs_ix
        parent=dirs_ix
        while ln_ix < len(lines):
            ln = lines[ln_ix].split()      

            if ln[1] == "cd":     
                if ln[2].isalpha() and ln[2]!='/':
                    parent=current_dir 
                    dirs.append(Dir(ln[2],parent))                                        
                    dirs_ix+=1
                    dirs[parent].addDir(dirs_ix)                  
                    current_dir = dirs_ix
                if ln[2] == "..":
                    current_dir=dirs[current_dir].getParent()
                    parent=dirs[current_dir].getParent()

            if ln[0].isdigit():
                dirs[current_dir].accSize(int(ln[0]))

            ln_ix+=1 
    
    return dirs

def calculateScoreEx1(input_file_name):
    
    dirs = getDirs(input_file_name)
    
    res_ex1=0
    for d in dirs: 
        sz=d.getSize(dirs)
        if sz<=100000:
            res_ex1+=sz
        
    return res_ex1

def calculateScoreEx2(input_file_name):    
    
    dirs = getDirs(input_file_name)

    unused_space=70000000-dirs[0].getSize(dirs)
    del_dir_sz=30000000-unused_space

    dirs_sz =[]
    for d in dirs: 
        dirs_sz.append(d.getSize(dirs))
    
    dirs_sz.sort()

    res_ex2=0
    for d_sz in dirs_sz:
        if d_sz>=del_dir_sz:
            res_ex2=d_sz
            break

    return res_ex2

if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")