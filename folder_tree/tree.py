import os
import glob
import queue
import datetime

q = queue.Queue()


# os.chdir(r"C:\\Users\\xxxx\\Pictures")
d = os.getcwd()
q.put(d)
filename = 'output.txt'
output = open(filename, 'a', encoding='utf')  # 書き込みモードでオープン
output.write(str(datetime.datetime.now()))
output.write("\n")
output.close()


def wfs(wd):
    try:
        files = glob.glob(wd+"/*")
        list = []
        for f in files:
            if not os.path.isfile(f):
                q.put(f)
            else:
                index = f.rfind("\\")+1
                f = f[index:]
                list.append(f)
        print("")
        print(wd)
        print(list)
        output = open(filename, 'a', encoding='utf')  # 書き込みモードでオープン
        output.write("\n"+wd+"\n")
        output.write(str(list))
        output.write("\n")
        output.close()
    except Exception as e:
        print(e)


while not q.empty():
    wfs(q.get())

output = open(filename, 'a', encoding='utf')  # 書き込みモードでオープン
output.write("\n")
