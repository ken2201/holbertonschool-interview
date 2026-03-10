#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics
"""
import sys


def print_stats(total_size, status_counts):
    """Print the accumulated statistics"""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


if __name__ == "__main__":
    total_size = 0
    status_counts = {200: 0, 301: 0, 400: 0, 401: 0,
                     403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                if len(parts) >= 7:
                    status_code = int(parts[-2])
                    file_size = int(parts[-1])

                    if status_code in status_counts:
                        status_counts[status_code] += 1
                    total_size += file_size

                    line_count += 1
                    if line_count % 10 == 0:
                        print_stats(total_size, status_counts)
            except (ValueError, IndexError):
                continue
    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_counts)
