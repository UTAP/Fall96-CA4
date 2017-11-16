import math

GOALKEEPER = "goalkeeper"
DEFENDER = "defener"
MIDFIELDER = "midfielder"
STRIKER = "striker"


class Player:
	"""docstring for Player"""
	def __init__(self, player_name, player_post, player_power):
		self.name = player_name
		self.post = player_post
		self.power = player_power
		

class Team:
	"""docstring for Team"""
	def __init__(self, team_name, stadium_name, stadium_capacity, stadium_impact, fans_in_statuim):
		self.name = team_name
		self.stadium_name = stadium_name
		self.stadium_capacity = stadium_capacity
		self.stadium_impact = stadium_impact 
		self.fans_in_stadium = fans_in_statuim
		self.players = []

	def add_player(self, player_name, player_power, player_post):
		self.players.append(Player(player_name, player_post, player_power))

	def count_team_power(self):
		defend = 0
		defend_number = 0
		midfield = 0
		midfield_number = 0
		attack = 0
		attack_number = 0

		for player in self.players:
			if player.post in [DEFENDER, GOALKEEPER]:
				defend += player.power
				defend_number += 1
			elif player.post == MIDFIELDER:
				midfield += player.power
				midfield_number += 1
			else:
				attack += player.power
				attack_number += 1

		defend = math.floor((defend/float(defend_number))*(((defend_number-1)/4.0)**0.5))
		midfield = math.floor((midfield/float(midfield_number))*((midfield_number/3.0)**0.5))
		attack = math.floor((attack/float(attack_number))*((attack_number/3.0)**0.5))

		return defend, midfield, attack


class Match:
	"""docstring for Match"""
	def __init__(self, team_1, team_2):
		self.team_1 = team_1
		self.team_2 = team_2

	def simulate(self):
		team_1_defend, team_1_midfield, team_1_attack = self.team_1.count_team_power()
		team_2_defend, team_2_midfield, team_2_attack = self.team_2.count_team_power()

		fans_team_1 = self.team_1.fans_in_stadium[self.team_1.stadium_name]
		fans_team_2 = self.team_2.fans_in_stadium[self.team_1.stadium_name]
		stadium_capacity = self.team_1.stadium_capacity
		# print "fans-1: {}, fans-2: {}, whole: {}".format(fans_team_1, fans_team_2, stadium_capacity)

		if (stadium_capacity - fans_team_1) < fans_team_2:
			fans_team_2 = stadium_capacity - fans_team_1

		stadium_impact_1 = math.floor(self.team_1.stadium_impact * (self.team_1.fans_in_stadium[self.team_1.stadium_name] / float(self.team_1.stadium_capacity)))
		stadium_impact_2 = math.floor(self.team_1.stadium_impact * (fans_team_2 / float(self.team_1.stadium_capacity)))

		# print "impact-1: {}, impact-2: {}".format(stadium_impact_1, stadium_impact_2)

		team_1_defend += stadium_impact_1
		team_1_midfield += stadium_impact_1
		team_1_attack += stadium_impact_1

		team_2_defend += stadium_impact_2
		team_2_midfield += stadium_impact_2
		team_2_attack += stadium_impact_2

		# print "{}: {}-{}-{}".format(self.team_1.name, team_1_defend, team_1_midfield, team_1_attack)
		# print "{}: {}-{}-{}".format(self.team_2.name, team_2_defend, team_2_midfield, team_2_attack)

		self.goal_team_1 = math.floor((((team_1_attack*team_1_midfield)/float((team_2_defend*team_2_midfield)))**(1.5))*(3.0))
		self.goal_team_2 = math.floor((((team_2_attack*team_2_midfield)/float((team_1_defend*team_1_midfield)))**(1.5))*(3.0))
		return self.goal_team_1, self.goal_team_2

fans_in_stadium = {}


fans_in_stadium["Camp Nou"] = 3000;
fans_in_stadium["Santiago Bernabeu"] = 2000;
fans_in_stadium["Emirates Stadium"] = 54000;
fans_in_stadium["Anfield"] = 10000;
arsenal = Team("Arsenal", "Emirates Stadium", 60000, 3, fans_in_stadium.copy());
arsenal.add_player("Ospina", 79, GOALKEEPER);
arsenal.add_player("Mertesacker", 81, DEFENDER);
arsenal.add_player("Koscielny", 84, DEFENDER);
arsenal.add_player("Bellerin", 81, DEFENDER);
arsenal.add_player("Monreal", 80, DEFENDER);
arsenal.add_player("Ozil", 88, MIDFIELDER);
arsenal.add_player("Cazorla", 83, MIDFIELDER);
arsenal.add_player("Ramsey", 82, MIDFIELDER);
arsenal.add_player("Lacazette", 85, STRIKER);
arsenal.add_player("Giroud", 82, STRIKER);
arsenal.add_player("Sanchez", 89, STRIKER);

fans_in_stadium["Camp Nou"] = 90000;
fans_in_stadium["Santiago Bernabeu"] = 10000;
fans_in_stadium["Emirates Stadium"] = 4000;
fans_in_stadium["Anfield"] = 5000;
barcelona = Team("Barcelona", "Camp Nou", 100000, 5, fans_in_stadium.copy());
barcelona.add_player("Ter Stegen", 85, GOALKEEPER);
barcelona.add_player("Sergi Roberto", 81, DEFENDER);
barcelona.add_player("Pique", 87, DEFENDER);
barcelona.add_player("Umtiti", 83, DEFENDER);
barcelona.add_player("Alba", 85, DEFENDER);
barcelona.add_player("Rakitic", 87, MIDFIELDER);
barcelona.add_player("Busquets", 86, MIDFIELDER);
barcelona.add_player("Iniesta", 87, MIDFIELDER);
barcelona.add_player("Suarez", 92, STRIKER);
barcelona.add_player("Messi", 93, STRIKER);
barcelona.add_player("Dembele", 83, STRIKER);

fans_in_stadium["Camp Nou"] = 3000;
fans_in_stadium["Santiago Bernabeu"] = 2000;
fans_in_stadium["Emirates Stadium"] = 10000;
fans_in_stadium["Anfield"] = 48000;
liverpool = Team("Liverpool", "Anfield", 54000, 4, fans_in_stadium.copy());
liverpool.add_player("Mignolet", 80, GOALKEEPER);
liverpool.add_player("Matip", 83, DEFENDER);
liverpool.add_player("Lovren", 81, DEFENDER);
liverpool.add_player("Alexander-Arnold", 68, DEFENDER);
liverpool.add_player("Moreno", 76, DEFENDER);
liverpool.add_player("Henderson", 82, MIDFIELDER);
liverpool.add_player("Wijnaldum", 82, MIDFIELDER);
liverpool.add_player("Coutinho", 86, MIDFIELDER);
liverpool.add_player("Firmino", 83, STRIKER);
liverpool.add_player("Mane", 82, STRIKER);
liverpool.add_player("Salah", 82, STRIKER);

fans_in_stadium["Camp Nou"] = 15000
fans_in_stadium["Santiago Bernabeu"] = 70000
fans_in_stadium["Emirates Stadium"] = 5000
fans_in_stadium["Anfield"] = 7500
real = Team("Real Madrid", "Santiago Bernabeu", 80000, 5, fans_in_stadium.copy())
real.add_player("Navas", 85, GOALKEEPER);
real.add_player("Ramos", 90, DEFENDER);
real.add_player("Varane", 85, DEFENDER);
real.add_player("Marcelo", 87, DEFENDER);
real.add_player("Carvajal", 84, DEFENDER);
real.add_player("Casemiro", 85, MIDFIELDER);
real.add_player("Kroos", 90, MIDFIELDER);
real.add_player("Modric", 89, MIDFIELDER);
real.add_player("Isco", 89, MIDFIELDER);
real.add_player("Benzema", 86, STRIKER);
real.add_player("Ronaldo", 94, STRIKER);

		
teams = [arsenal, barcelona, liverpool, real]

matches_1 = [Match(arsenal, barcelona), Match(barcelona, arsenal), Match(liverpool, real), Match(real, liverpool)]
matches_2 = [Match(barcelona, real), Match(real, barcelona)]

def simulate_round(round, round_number):
	print "Round {}".format(round_number)
	i = 1
	goals_1 = 0
	goals_2 = 0
	winner = ""
	for match in round:
		if i % 2 == 1:
			winner = ""
			goals_1 = 0
			goals_2 = 0
			print str((i+1)/2) + ":"
		# print match.team_1.name + " vs " + match.team_2.name
		match.simulate()
		print "\t{} {} - {} {}".format(match.team_1.name, int(match.goal_team_1), int(match.goal_team_2), match.team_2.name)
		
		if i % 2 == 0:
			goals_1 += int(match.goal_team_1)
			goals_2 += int(match.goal_team_2)
			if goals_1 > goals_2:
				winner = match.team_1.name
			else:
				winner = match.team_2.name
		else:
			goals_2 += int(match.goal_team_1)
			goals_1 += int(match.goal_team_2)
			

		if i % 2 == 0:
			print "\t=> winner: {}".format(winner)
		i += 1

simulate_round(matches_1, 1)
simulate_round(matches_2, 2)

