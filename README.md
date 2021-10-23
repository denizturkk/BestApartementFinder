# BestApartementFinder(NOT FINISHED)
In this project, The scenario is that as a real estate company we want to find/suggest the best apartment to our customers from their preference on the new real estate project consisting of many new buildings. We have a list of buildings in the data.txt file. Each building can have different opportunities as social facilities within itself (gym, school, neighborhood, pool). These new apartments are built one after the other on a street. If a building does not have a facility(it could be any of the 4 facilities). The Owner of the home in this building could benefit the other building's facilities. So in this case, to evaluate the buildings for each different customer. We look at the nearest building in both directions which have the facility that the current building does not have. When we find the nearest building, We look what is the distance between these 2 buildings(|current building number-the nearest building number which have the facility|). Then we will multiply this int value with the importance value which is taken from the customer.After doing that for four different facility.Finally we get a final score by adding the 4 different facility score. So the lower score of buildings means that the buildings correspond with the demands of customers. After calculations we can print the results ordered by score or oredered by apartment number.

data.txt file is like:
buildingId,pool,gym,school,good neighboor
1,1,1,0,0
2,1,0,0,0
3,0,0,1,1
4,1,1,1,1
5,1,0,1,0
6,1,0,0,1
7,0,0,1,0

first number of the lines is the idNumber of the building.
The rest is the information of the facilities.
if it is 1 it means exist a facility, if it is 0 not exist a facility

--after the execution of the program, you should type "data".

