#include <stdio.h>
#include <stdint.h>
#include <getopt.h>
#include <stdlib.h>

enum enum_opt {
  OPT_HELP = 1,
  OPT_EGGS,
  OPT_FLOORS,
  OPT_SAFE_FLOOR
};

struct option lopts[] = {
  {"help", no_argument, NULL, OPT_HELP},
  {"eggs", required_argument, NULL, OPT_EGGS},
  {"floors", required_argument, NULL, OPT_FLOORS},
  {"safe-floor", required_argument, NULL, OPT_SAFE_FLOOR},
};

void help()
{
  printf("Program to perform optimized checks to find which floor is safest\n");
  printf("among m floors, when eggs are dropped.\n");
  printf("This program takes input as n eggs, m floors, and safe floor\n");
  printf("By using these inputs the program gives output as how many\n");
  printf("minimum checks are needed to find the safe floor\n");
  printf("\nUsage:\n");
  printf("<exe> --eggs <count> --floors <count> --safe-floor <floor-num>\n");
  exit(0);
}

uint32_t m_floors, n_eggs, safe_floor;
uint32_t num_of_checks = 0;

int check_safe(uint32_t floor)
{
  num_of_checks++;
  if (floor <= safe_floor) return 1;
  return 0;
}

uint32_t find_safest_floors(uint32_t n_eggs, uint32_t m_floors)
{
  uint32_t start = 1, floor;
  uint32_t end = m_floors;
  printf("%u eggs and %u floors\n", n_eggs, m_floors);
  do {
    printf("Check among floors between %u and %u with %u eggs\n", start, end,
            n_eggs);
    /* Always start and end points to the unchecked floors */
    if (n_eggs > 1) {
      printf(" - Doing binary traversal\n");
      /* Do binary traversal */
      if (end != start) {
        floor = start + ((end - start) / 2);
      } else {
        floor = start;
        /* This is the last check */
      }
    } else {
      printf(" - Doing linear traversal\n");
      /* Do linear traversal */
      floor = start;
      /* TODO Need to add max check */
    }
    printf(" - Checking floor %u\n", floor);
    if (check_safe(floor) == 1) {
      printf(" - %u is safe floor\n", floor);
      if (floor < end) {
        /* Checking floor range adjustment */
        /* If some more floors are there then point start next to
         * current floor. */
        start = floor + 1;
      } else {
        /* else we found it */
        return floor;
      }
    } else {
      printf(" - %u is unsafe floor\n", floor);
      if (n_eggs > 1) {
        /* If we are in binary traversal */
        n_eggs--; /* Reduce egg count, as one egg is broken */
        if (floor > start) {
          /* Checking floor range adjustment */
          /* If current checking floor is greater than start then
           * assign (floor - 1) to end. */
          end = floor - 1;
        } else {
          /* else we found it */
          return (floor - 1);
        }
      } else {
        /* else in linear traversal */
        /* Found it */
        return (floor - 1);
      }
    }
  } while (1);
}

int main(int argc, char *argv[])
{
  uint32_t floor;
  int opt;
  while ((opt = getopt_long(argc, argv, "", lopts, NULL)) != -1) {
    switch (opt) {
      case OPT_EGGS:
        n_eggs = atoi(optarg);
        break;
      case OPT_FLOORS:
        m_floors = atoi(optarg);
        break;
      case OPT_SAFE_FLOOR:
        safe_floor = atoi(optarg);
        break;
      case OPT_HELP:
      default:
        help();
    }
  }

  if ((n_eggs == 0) || (m_floors == 0)) {
    printf("Invalid eggs(%u) or floors(%u)\n", n_eggs, m_floors);
    return -1;
  }
  floor = find_safest_floors(n_eggs, m_floors);
  printf("It took %u checks to find safest floor %u out of %u floors with %u " \
          "eggs\n", num_of_checks, floor, m_floors, n_eggs);
  return 0;
}
