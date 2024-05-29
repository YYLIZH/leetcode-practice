from pathlib import Path
import argparse


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("directory", help="directory name")
    args = parser.parse_args()

    dirname = args.directory.replace(".", "").replace(" ", "-")
    dirname_path = Path(dirname)

    dirname_path.mkdir(exist_ok=True, parents=True)
    (dirname_path / "solution.py").touch()
    (dirname_path / "solution.cpp").touch()
