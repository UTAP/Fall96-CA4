import random
import math

team_a = {"attack": 90.0, "defend": 90.0, "midfield": 90.0, "name": "Barcelona"}

team_b = {"attack": 70.0, "defend": 100.0, "midfield": 70.0, "name": "Athletico"}
# team_b = {"attack": 70.0, "defend": 70.0, "midfield": 70.0, "name": "Liverpool"}
# team_b = {"attack": 90.0, "defend": 70.0, "midfield": 80.0, "name": "Dortmond"}
# team_b = {"attack": 90.0, "defend": 90.0, "midfield": 90.0, "name": "RealMadrid"}

for i in xrange(1,10):
	goal_a = math.floor((((team_a["attack"] / team_b["defend"]) * (team_a["midfield"] / team_b["midfield"])) ** (1.5)) * random.random() * 3)
	goal_b = math.floor((((team_b["attack"] / team_a["defend"]) * (team_b["midfield"] / team_a["midfield"])) ** (1.5)) * random.random() * 3)

	print "{} {} - {} {}".format(team_a["name"], goal_a, team_b["name"], goal_b)