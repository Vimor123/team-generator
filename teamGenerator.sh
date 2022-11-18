#!/bin/bash

read -p "Names (delimiter : \",\") : " playersString
read -p "Number of teams : " noOfTeams

IFS=','
read -ra players <<< "$playersString"

noOfPlayers=${#players[@]}


for (( i=0; i<$noOfPlayers; i++ )); do
	remainingPlayers=$(($noOfPlayers - $i))
	randomIndex=$(($RANDOM % $remainingPlayers))
	helper=${players[$randomIndex]}
	players[$randomIndex]=${players[$(($remainingPlayers - 1))]}
	players[$(($remainingPlayers - 1))]=$helper
done


minPlayersPerTeam=$(($noOfPlayers / $noOfTeams))
for (( i=0; i<$noOfTeams; i++ )); do
	playersPerTeam+=($minPlayersPerTeam)
done

additionalPlayers=$(($noOfPlayers % $noOfTeams))
for (( i=0; i<$additionalPlayers; i++ )); do
	playersPerTeam[$i]=$((${playersPerTeam[$i]} + 1 ))
done


echo ''
allPlayerIndex=0

for (( i=0; i<$noOfTeams; i++ )); do
	printf "Team %d\n" "$(($i + 1))"
	printf "====================\n"
	for (( j=0; j<${playersPerTeam[$i]}; j++ )); do
		echo ${players[$allPlayerIndex]} | xargs
		allPlayerIndex=$(($allPlayerIndex + 1))
	done
	printf "\n"
done
