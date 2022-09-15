import random


def splitPeopleIntoTeams(people, noOfTeams):
    
    if len(people) < noOfTeams:
        noOfTeams = len(people)

    teams = []

    for teamIndex in range(noOfTeams):
        teams.append([])

    teamIndex = 0

    while len(people) != 0:
        chosenPerson = random.choice(people)
        people.remove(chosenPerson)
        teams[teamIndex].append(chosenPerson)
        teamIndex += 1
        
        if teamIndex == noOfTeams:
            teamIndex = 0

    return teams



def printTeams(teams):

    for teamIndex in range(len(teams)):

        print("\nTeam " + str(teamIndex + 1))
        print("=" * 20)

        for person in teams[teamIndex]:
            print(person)

    print("")



def main():
    
    people = list(map(str, input("Names (delimiter : ',') : ").split(',')))
    people = list(map(lambda person: person.strip(), people))

    noOfTeams = int(input("Number of teams : "))

    teams = splitPeopleIntoTeams(people, noOfTeams)

    printTeams(teams)



if __name__ == "__main__":
    main()
