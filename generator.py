import sys
import random


def CustomGenerator(seed: int) -> None:
    random.seed(seed)


CustomGenerator(int(sys.argv[1]))
