 Node *newAppointment = new Node{name, startTime, endTime, nullptr};
        cout << "Booking an appointment for " << newAppointment->name << ", scheduled at " << newAppointment->starttime << ":" << newAppointment->endtime << endl;

        if (head == nullptr || endTime <= head->starttime)
        {
            newAppointment->next = head;
            head = newAppointment;
            count++;
            cout << "Appointment booked successfully" << endl;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && endTime > current->next->starttime)
        {
            current = current->next;
        }
        newAppointment->next = current->next;
        current->next = newAppointment;