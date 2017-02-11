require 'open-uri'
require 'json'
require './lib/nyc_hospitals'

def scraper
  new_hash = JSON.parse(File.read(open "https://data.cityofnewyork.us/api/views/f7b6-v6v3/rows.json?accessType=DOWNLOAD"))

  brooklyn = {}
  staten_island = {}
  manhattan = {}
  bronx = {}
  queens = {}

  new_hash["data"].each do |hosp|
    if hosp[9] == "Queens"
      queens[hosp[10]] = {:name => hosp[10], :type => hosp[8], :phone_number => hosp[12], :address => hosp[13][0]}
    elsif hosp[9] == "Brooklyn"
      brooklyn[hosp[10]] = {:name => hosp[10], :type => hosp[8], :phone_number => hosp[12], :address => hosp[13][0]}
    elsif hosp[9] == "Manhattan"
      manhattan[hosp[10]] = {:name => hosp[10], :type => hosp[8], :phone_number => hosp[12], :address => hosp[13][0]}
    elsif hosp[9] == "Bronx"
      bronx[hosp[10]] = {:name => hosp[10], :type => hosp[8], :phone_number => hosp[12], :address => hosp[13][0]}
    else # Staten Island
      staten_island[hosp[10]] = {:name => hosp[10], :type => hosp[8], :phone_number => hosp[12], :address => hosp[13][0]}
    end
  end

  NycHospitals::NycHospitals.new(brooklyn, staten_island, manhattan, bronx, queens)

end


# 12 - Phone number
# 8 - type
# 9 - Borough
# 10 - name
# hosp[13][0] - address
