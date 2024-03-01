import argparse
from random import randint, uniform, seed

def generate_airplanes(num_planes, float_coords):
    airplanes = []
    for _ in range(num_planes):
        start_x = randint(1, 1920)
        start_y = randint(1, 1080)
        end_x = randint(1, 1920)
        end_y = randint(1, 1080)
        speed = randint(1, 3)
        if float_coords:
            delay = uniform(0, 5)
        else:
            delay = randint(0, 5)
        airplanes.append(f"A {start_x} {start_y} {end_x} {end_y} {speed} {delay}")
    return airplanes

def load_towers_from_file(file_path):
    towers = []
    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()
            if line.startswith('T'):
                parts = line.split()
                if len(parts) == 4:
                    x, y, radius = map(int, parts[1:])
                    towers.append(f"T {x} {y} {radius}")
    return towers

def generate_towers(num_towers, float_coords, tower_file=None):
    towers = []
    if tower_file:
        towers += load_towers_from_file(tower_file)
    else:
        for _ in range(num_towers):
            x = randint(1, 1920)
            y = randint(1, 1080)
            radius = randint(1, 500)
            towers.append(f"T {x} {y} {radius}")
    return towers

def save_to_file(filename, content):
    with open(filename, 'w') as f:
        f.write('\n'.join(content))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', '--planes', metavar="Planes", required=True, type=int, help="Number of airplanes")
    parser.add_argument('-t', '--towers', metavar="Towers", required=True, type=int, help="Number of towers")
    parser.add_argument('-f', '--float', metavar="Float Coordinates", default=False, choices=[True, False], type=bool, help="Can coordinates contain floating numbers")
    parser.add_argument('-s', '--seed', metavar="Seed", default=None, type=int, help="Seed for random number generation")
    parser.add_argument('-o', '--output', metavar="Output File", default="output.txt", type=str, help="Output file path")
    parser.add_argument('-tf', '--tower-file', metavar="Tower File", default=None, type=str, help="File containing tower locations")
    args = parser.parse_args()

    if args.seed is not None:
        seed(args.seed)

    if args.float:
        float_coords = True
    else:
        float_coords = False

    airplanes = generate_airplanes(args.planes, float_coords)
    towers = generate_towers(args.towers, float_coords, tower_file=args.tower_file)

    content = airplanes + towers
    save_to_file(args.output, content)

if __name__ == "__main__":
    main()
