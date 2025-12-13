from itertools import combinations
from scipy.optimize import linprog
import numpy as np


class AdventDay10:

    def __init__(self, filename='input.txt'):
        # Modified to read from a file instead of DayStarter
        try:
            with open(filename, 'r') as f:
                self.data = [x.strip() for x in f.readlines()]
        except FileNotFoundError:
            print(f"Error: {filename} not found.")
            self.data = []
            
        self._process_data()
        self.part1 = 0
        self.part2 = 0

    def _process_data(self):
        self.machines = []
        for line in self.data:
            if line == '':
                continue
            parts = line.split(' ')
            machine = {
                'lights': self._read_contents(parts[0]),
                'buttons': [self._read_contents(x) for x in parts[1:-1]],
                'joltage': self._read_contents(parts[-1])
            }
            self.machines.append(machine)

    def _read_contents(self, string):
        result = []
        # Handle empty or malformed brackets/braces
        if len(string) < 2: 
            return result
            
        for char in string[1:-1].split(','):
            if not char: continue 
            try:
                result.append(int(char))
            except ValueError:
                result.append(char)
        
        # If the result is meant to be a list of characters (like lights) or numbers, return list.
        # The original logic seemed to flatten single-item lists which might be risky if inconsistent.
        # Based on your input format like [.##.], it returns a string/list of chars.
        if len(result) > 0 and isinstance(result[0], int):
            return result
        # For lights like [.##.], result is list of chars ['.', '#', '#', '.']
        # For single items or characters
        if len(result) == 1:
             # This check existed in your code, keeping strictly as requested,
             # though strictly logic might need specific adjustment depending on exactly what 'lights' needs to be.
             # In your code: [.##.] -> ['.', '#', '#', '.'] -> handled by _read_contents logic?
             # actually string[1:-1] of [.##.] is ".##."
             # split(',') would be ['.##.'] if no commas.
             # Original code logic:
             # if string is [.##.], split(',') -> ['.##.']
             # result -> ['.##.']
             # returns result[0] -> '.##.' (string) which is iterable.
             pass
             
        # Replicating original return logic mostly, but safer for lights strings
        if len(result) > 0 and isinstance(result[0], str) and len(result[0]) > 1:
             return result[0] # Returns the string itself
        
        # If it parsed distinct items (like numbers) return the list
        return result

    def minimal_light_presses(self):
        for machine in self.machines:
            lights = machine['lights']
            buttons = machine['buttons']
            n = len(lights)
            needed = [i for i in range(n) if lights[i] == '#']
            found = False
            presses = 0
            
            # Safety break to prevent infinite loops if unsolvable
            while not found and presses <= len(buttons): 
                presses += 1
                for comb in combinations(buttons, presses):
                    if self._use_combinations(lights, comb, needed):
                        found = True
                        break
            if found:
                self.part1 += presses

    def minimal_joltage_presses(self):
        for machine in self.machines:
            buttons = machine['buttons']
            joltage = machine['joltage']
            
            # Construct matrix A: columns are buttons, rows are joltage counters
            # A[row][col] = 1 if button col affects counter row
            A = np.array([[int(i in button) for i in range(len(joltage))]
                          for button in buttons]).transpose()
            b = np.array(joltage)
            
            # Objective: minimize sum of presses (all weights = 1)
            c = [1 for _ in range(len(buttons))]
            
            # integrality=1 forces integer solutions
            # bounds=(0, None) is default (non-negative)
            solution = linprog(c=c, A_eq=A, b_eq=b, integrality=1)
            
            if solution.success:
                self.part2 += solution.fun
                
        self.part2 = int(self.part2)

    def _use_combinations(self, lights, comb, needed):
        current = [0 for _ in lights]
        for button in comb:
            for index in button:
                current[index] += 1
        found = True
        for i, val in enumerate(current):
            # Modular arithmetic (mod 2) check
            if val % 2 == 0 and i in needed:
                found = False
                break
            if val % 2 == 1 and i not in needed:
                found = False
                break
        return found


if __name__ == '__main__':
    # Ensure input.txt exists in the same directory
    day10 = AdventDay10('input.txt')
    day10.minimal_light_presses()
    day10.minimal_joltage_presses()
    print(day10.part1, day10.part2)
