# volunteer-management-system
A system to manage volunteers, organisers and events.
The system is written in C++, and users can begin by executing the ```system.exe``` file.
Project completed by @ziching18, @libunn, @eethiing, and @zshane57.

<h2>About VMS</h2>
<p>The Volunteer Management System, or VMS, for short, is a system made specifically to manage volunteering work for people interested in lending a helping hand to society. The main objective of this project is to provide a centralised system that enables both the volunteers and organisations to utilise it. The volunteers will be able to view all the events list as well as requirements and decide the event that they would like to participate in whereas the organisations will be able to submit their event details to search for volunteers from a wider range of crowd. </p>
<p>Our system users include volunteers and admins. Volunteers can sign up once and log in to the system once their account has been created. The volunteer can search and register for the events that they are interested in. They can also view and edit their own profile. Admins have access to all volunteer and event details. Admins can add events from approved applications into the system, and also delete both existing volunteers and events from the system. </p>
<p>We aim to make the system user-friendly and aesthetically pleasing for optimum user experience, as well as bringing convenience to both volunteers and organisations.</p>


<h2>File Structure</h2>

<b>Volunteer</b></br>
There are 3 volunteer related files/folders: 
- ```login.txt```: volunteer login information (username, password)
- ```v_id.txt```: all volunteer IDs
- ```Volunteer/v_id.txt```: folder with individual volunteer files with their information, with their IDs are file name

<b>Event</b></br>
There are 4 event related files/folders:
- ```eventName.txt```: event names
- ```e_id.txt```: all event IDs
- ```Event/e_id.txt```: folder with individual event files with their information, with their IDs are file name
- ```Event/Registered/e_id.txt```: volunteer IDs of those registered for the event

<b>Admin</b></br>
Credentials:
- username: ```admin```
- password: ```iloveliwen```
