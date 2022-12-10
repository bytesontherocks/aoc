class Dir:
    nested_dirs = []
    parent = 0
    size = 0
    total_size = 0 #account nested
    def __init__(self, id, parent):
        self.id=id
        self.parent=parent

    def getId(self):
        return self.id
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
    def getDir(self, id):
        for d in self.nested_dirs:
            if d.getId() == id:
                return d
            else:
                return None
    def getIdAndSize(self):
        return self.id,self.getSize()


def calculateScoreEx1(input_file_name):
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        ln_ix=0 
        dirs =[]
        dirs.append(Dir('/', 0))#create root
        dirs_ix = 0
        current_dir = dirs_ix
        parent=dirs_ix
        root = parent
        while ln_ix < len(lines):
            ln = lines[ln_ix].split()      

            if ln[1] == "cd":     
                if ln[2].isalpha() and ln[2]!='/':
                    dirs.append(Dir(ln[2],current_dir))                     
                    dirs_ix+=1
                    dirs[parent].addDir(dirs_ix)                    
                    parent=dirs_ix-1                 
                    current_dir = dirs_ix
                if ln[2] == "..":
                    current_dir=dirs[current_dir].getParent()
                    parent=dirs[current_dir].getParent()

            if ln[0].isdigit():
                dirs[current_dir].accSize(int(ln[0]))
            ln_ix+=1 
            if ln_ix >= len(lines):
                break
        for d in dirs: 
            print(d.getSize(dirs))
        
    return 0

def calculateScoreEx2(input_file_name):    
    f = open(input_file_name, "r")
    lines = f.readlines()  
    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input_sample.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")