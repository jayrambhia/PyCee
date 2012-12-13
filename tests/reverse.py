import pycee
def reverseTest():
    s = "Jim Morrsion!"
    str1 = pycee.reverse("Jim Morrsion!")
    if str1 == "!noisrroM miJ":
        pass
    else:
        assert False

if __name__ == "__main__":
    reverseTest()
