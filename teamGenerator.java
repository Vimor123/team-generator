import java.util.*;

public class teamGenerator {
    
	public static void main(String[] args) {
	    
		Scanner sc = new Scanner(System.in);
		
		System.out.printf("Names (delimiter = \",\") : ");
		String allPlayers = sc.nextLine();
		
		String[] playersArray = allPlayers.split(",", 0);
		
		List<String> players = Arrays.asList(playersArray);
		
		for(int playerIndex = 0; playerIndex < players.size(); playerIndex++) {
		    players.set(playerIndex, players.get(playerIndex).trim());
		}
		
		System.out.printf("Number of teams : ");
		int noOfTeams = sc.nextInt();
		
		sc.close();
		
		List<Team> teams = Team.splitPlayersIntoTeams(players, noOfTeams);
		
		System.out.printf("\n");
		for (Team team : teams) {
		    team.printTeam();
		}
	}
}


class Team {
    private String teamName;
    private List<String> players;
    
    public Team(String teamName) {
        this.teamName = teamName;
        players = new ArrayList<String>();
    }
    
    public String getTeamName() {
        return teamName;
    }
    
    public List<String> getPlayers() {
        return players;
    }
    
    public void setTeamName(String teamName) {
        this.teamName = teamName;
    }
    
    public void setPlayers(List<String> players) {
        this.players = players;
    }
    
    public void addPlayer(String player) {
        players.add(player);
    }
    
    public void printTeam() {
        System.out.println(teamName);
        
        String divider = "=".repeat(20);
        System.out.println(divider);
        
        for(String player : players) {
            System.out.println(player);
        }
        
        System.out.printf("\n");
    }
    
    public static List<Team> splitPlayersIntoTeams(List<String> players, int noOfTeams) {
        List<Team> teams = new ArrayList<Team>();
        
        Random rand = new Random();
        
        int teamIndex;
        int randomPlayerIndex;
        Team team;
        
        List<String> playersCopy = new ArrayList<String>();
        
        for(int playerIndex = 0; playerIndex < players.size(); playerIndex++) {
            playersCopy.add(players.get(playerIndex));
        }
        
        for(teamIndex = 0; teamIndex < noOfTeams; teamIndex++) {
            String teamName = "Team " + String.valueOf(teamIndex + 1);
            teams.add(new Team(teamName));
        }
        
        teamIndex = 0;
        
        while(playersCopy.size() > 0) {
            randomPlayerIndex = rand.nextInt(playersCopy.size());
            
            team = teams.get(teamIndex);
            team.addPlayer(playersCopy.get(randomPlayerIndex));
            
            playersCopy.remove(randomPlayerIndex);
            
            teamIndex++;
            
            if(teamIndex >= noOfTeams) {
                teamIndex = 0;
            }
        }
	
        return teams;
    }
}
