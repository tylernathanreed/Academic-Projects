//* Description *//
// Title: Confirm Delete
// Author: Tyler Reed
// Defines a Static Class to utilize the Confirm Delete Form

//* Libraries *//
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

//* Namespace *//
namespace Contact_Manager_Client
{
    // Confirm Delete Class
    static class ConfirmDeleteDialog
    {
        //* Class Variables *//
        public static int OPTION_YES = 1;
        public static int OPTION_REMINDER = 2;

        // Shows the Confirm Delete Dialog and Returns its Value
        public static int Show()
        {
            Form_ConfirmDelete form_confirmDelete = new Form_ConfirmDelete();
            return form_confirmDelete.ReturnDialog();
        }
    }
}
