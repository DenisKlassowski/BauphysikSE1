def layer_calc(l):
    calc_r(l)


def tab_calc(t):
    if t.mode == 0:  # u calculation
        full_u_calc(t)
    elif t.mode == 1:  # temp calculation
        #if t.u == 0.0:
            #full_u_calc(t)
        full_u_calc(t)

        j = t.u * (t.tin - t.tout)
        rho_inside = t.rsi * j
        rho_outside = t.rse * j

        for i in range(len(t.layers)):
            t.layers[i].rho = t.layers[i].r * j

            """
            if t.tout < t.tin:
                if i == 0:
                    t.layers[i].t_inside = t.tin - rho_inside
                else:
                    t.layers[i].t_inside = t.layers[i - 1].t_outside

                t.layers[i].t_outside = t.layers[i].t_inside - t.layers[i].rho
            elif t.tout > t.tin:
                if i == 0:
                    t.layers[i].t_inside = t.tin + rho_inside
                else:
                    t.layers[i].t_inside = t.layers[i - 1].t_outside

                t.layers[i].t_outside = t.layers[i].t_inside + t.layers[i].rho
            else:
                t.layers[i].t_inside = t.tout
                t.layers[i].t_outside = t.tout
            """
            if i == 0:
                t.layers[i].t_outside = t.tout + rho_outside
            else:
                t.layers[i].t_outside = t.layers[i - 1].t_inside

            t.layers[i].t_inside = t.layers[i].t_outside + t.layers[i].rho

    # elif t.mode == 3:  # ....


def full_u_calc(t):
    r = calc_all_r(t.layers)
    rt = calc_rt(t.rsi, t.rse, r)
    u = calc_u(rt)
    t.rges = r
    t.u = u
    t.rt = rt


def calc_rt(rsi, rse, r):
    return rsi + rse + r


def calc_u(rt):
    return 1 / rt


def calc_all_r(layers):
    r = 0
    for layer in layers:
        if layer.r == 0.0:
            r += calc_r(layer)
        else:
            r += layer.r
    return r


def calc_r(layer):
    layer.r = layer.width / layer.lambda_
    return layer.r
