
def bbq_skewer(grill):
    veg = len([i for i in grill if "-o" in i and "-x" not in i])
    non_veg = len([i for i in grill if "-x" in i])
    return (veg, non_veg)


if __name__ == "__main__":
    grill = ["--xo--x--ox--",
             "--xx--x--xx--",
             "--oo--o--oo--",
             "--xx--x--ox--",
             "--xx--x--ox--"]

    print(bbq_skewer(grill))
