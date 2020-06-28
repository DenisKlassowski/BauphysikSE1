class Exporter:
    def __init__(self, tab):
        self.tab = tab

    def export(self, filename):
        print("yee")
        data = ""
        data += "name: " + self.tab.name + "\n"
        data += "rright: " + str(self.tab.rright) + "\n"
        data += "rleft: " + str(self.tab.rleft) + "\n"
        data += "rsum: " + str(self.tab.rsum) + "\n"
        data += "tright: " + str(self.tab.tright) + "\n"
        data += "tleft: " + str(self.tab.tleft) + "\n"
        data += "mode: " + str(self.tab.mode) + "\n"
        data += "u: " + str(self.tab.u) + "\n"
        data += "rt: " + str(self.tab.rt) + "\n"

        layers = "layers:\n"

        for layer in self.tab.layers:
            layers += "\tlayer: "
            layers += str(layer.width) + ", "
            layers += str(layer.widthUnit) + ", "
            layers += str(layer.lambda_) + ", "
            layers += str(layer.r) + ", "
            layers += str(layer.t_left) + ", "
            layers += str(layer.t_right) + ", "
            layers += str(layer.rho) + ", "
            layers += str(layer.mat) + "\n"

        full_string = data + layers
        f = open(filename, "w")
        f.write(full_string)
        print(f)
        f.close()
