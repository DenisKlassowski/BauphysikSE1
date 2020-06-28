import LayerData
import TabData


class Parser:
    def __init__(self, filename):
        self.filename = filename

    def parse(self):
        f = open(self.filename, "r")

        td = TabData.TabData(0, "")

        for line in f.readlines():
            data = line.split(": ")

            if len(data) >= 2:
                if data[0] == "name":
                    td.name = data[1].split("\n")[0]
                elif data[0] == "rright":
                    td.rright = float(data[1])
                elif data[0] == "rleft":
                    td.rleft = float(data[1])
                elif data[0] == "rsum":
                    td.rsum = float(data[1])
                elif data[0] == "tright":
                    td.tright = float(data[1])
                elif data[0] == "tleft":
                    td.tleft = float(data[1])
                elif data[0] == "u":
                    td.u = float(data[1])
                elif data[0] == "rt":
                    td.rt = float(data[1])
                elif data[0] == "mode":
                    td.mode = int(data[1])
                elif data[0] == "\tlayer":
                    ld = data[1].split(", ")
                    td.add_layer(LayerData.LayerData(int(ld[7]), float(ld[3]), float(ld[2]), float(ld[0]), int(ld[1])))

        f.close()

        return td
