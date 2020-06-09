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

            if len(data) == 2:
                if data[0] == "name":
                    td.name = data[1]
                elif data[0] == "rright":
                    td.rright = data[1]
                elif data[0] == "rleft":
                    td.rleft = data[1]
                elif data[0] == "rsum":
                    td.rsum = data[1]
                elif data[0] == "tright":
                    td.tright = data[1]
                elif data[0] == "tleft":
                    td.tleft = data[1]
                elif data[0] == "u":
                    td.u = data[1]
                elif data[0] == "rt":
                    td.rt = data[1]
                elif data[0] == "mode":
                    td.mode = data[1]
                elif data[0] == "layers":
                    ld = data[1].split(", ")
                    td.add_layer(LayerData.LayerData(ld[0], ld[1], ld[2], ld[3], ld[7]))

        return td
