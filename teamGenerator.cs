using System;
using System.Collections.Generic;
using System.Linq;

public class teamGenerator {
    private static void Main(string[] args)
    {
        Console.Write("Names (delimiter = \",\") : ");
        string allPlayers = Console.ReadLine();

        string[] playerArray = allPlayers.Split(',');

        List<string> playerList = playerArray.ToList();

        for (int playerIndex = 0; playerIndex < playerList.Count; playerIndex++) {
            playerList[playerIndex] = playerList[playerIndex].Trim();
        }

        Console.Write("Number of teams : ");
        int noOfTeams = int.Parse(Console.ReadLine());

        List<Team> teams = Team.SplitPlayersIntoTeams(playerList, noOfTeams);

        Console.WriteLine();
        foreach (var team in teams) {
            team.PrintTeam();
        }
    }
}

class Team {
    private string teamName;
    private List<string> players;

    public Team(string teamName) {
        this.teamName = teamName;
        players = new List<string>();
    }

    public string GetTeamName() {
        return teamName;
    }

    public List<string> GetPlayers() {
        return players;
    }

    public void SetTeamName(string teamName) {
        this.teamName = teamName;
    }

    public void SetPlayers(List<string> players) { 
        this.players = players;
    }

    public void AddPlayer(string player) {
        players.Add(player);
    }

    public void PrintTeam() {
        Console.WriteLine(teamName);

        string divider = new string('=', 20);
        Console.WriteLine(divider);

        foreach (string player in players) {
            Console.WriteLine(player);
        }

        Console.WriteLine();
    }

    public static List<Team> SplitPlayersIntoTeams(List<string> players, int noOfTeams) {
        List<Team> teams = new List<Team>();
        Random rand = new Random();

        int teamIndex;
        int randomPlayerIndex;

        List<string> playersCopy = new List<string>();
        foreach (string player in players) { 
            playersCopy.Add(player);
        }

        for (teamIndex = 0; teamIndex < noOfTeams; teamIndex++) {
            string teamName = "Team " + (teamIndex + 1).ToString();
            teams.Add(new Team(teamName));
        }

        teamIndex = 0;
        while (playersCopy.Count > 0) { 
            randomPlayerIndex = rand.Next(playersCopy.Count);

            teams[teamIndex].AddPlayer(playersCopy[randomPlayerIndex]);

            playersCopy.RemoveAt(randomPlayerIndex);

            teamIndex++;

            if (teamIndex >= noOfTeams) {
                teamIndex = 0;
            }
        }

        return teams;
    }
}