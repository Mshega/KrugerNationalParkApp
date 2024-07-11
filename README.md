# Kruger National Park Application

The application focuses on various operations related to the Kruger National Park, utilizing a provided Access database (KrugerPark.accdb).

## Project Structure

The project is divided into the following main components:

- **Camps Table:** Contains data about different camps within the park.
- **CampTypes Table:** Describes various camp types.
- **AccommodationTypes Table:** Contains accommodation type codes and descriptions.
- **Clients Table:** Contains data about visitors who have visited the park.
- **ClientWildCards Table:** Contains information about clients with wildcards.
- **WildCard Table:** Contains wildcard types and their details.
- **Rangers Table:** Contains data about rangers assigned to base camps.
- **Sightings Table:** Contains records of animal sightings by rangers.
- **TariffRates Table:** Contains data on the rates per night for various accommodation types at different camps.

## Setup Instructions

### Prerequisites

- Embarcadero RAD Studio
- Access to the provided Access database file `KrugerPark.accdb`

### Getting Started

1. **Clone the Repository**
    ```bash
    git clone https://github.com/yourusername/KrugerNationalParkApp.git
    cd KrugerNationalParkApp
    ```

2. **Open the Project**
   - Open Embarcadero RAD Studio.
   - Open the project file located in the cloned repository.

3. **Setup the Database Connection**
   - In the project, locate the DataModule.
   - Set the connection settings using the object inspector to point to `KrugerPark.accdb`.
   - Ensure the connection is configured correctly for design-time and run-time purposes.

4. **Run the DEMO Application**
   - Navigate to the `debug` folder.
   - Click on the provided "speed button" at the top right-hand side to connect to the database.
   - Verify that the application connects successfully to the database.

## Application Features

### Tab Sheet ONE
1. **Loyalty Points Incentive Calculation**
   - Sum up the total "Loyalty points" for clients with wildcards and calculate the total incentive amount.
   - Implement this using SQL queries and ADO constructs.

### Tab Sheet TWO
1. **Populate Combo Box with Wildcard Types**
   - On showing the tab, populate the combo box with "Wildcard Code - Wildcard Description" from the `ADOdsWildCard` dataset.

2. **Display Associated Client Records**
   - Based on the selected wildcard type, display the corresponding client records in a DBGrid.

3. **Generate New Wildcard Number**
   - Generate a new unique WildCard number based on the existing data and display it.

4. **Insert a New Wildcard Record**
   - Insert a new record into the `ClientWildCards` table with the user-selected data.

5. **Display Updated Client Wildcards**
   - Refresh the displayed data to show the newly added record.

## Conclusion

This application demonstrates the usage of C++ with database connectivity to manage various operations within the Kruger National Park. 
Follow the instructions above to set up and run the application successfully.
