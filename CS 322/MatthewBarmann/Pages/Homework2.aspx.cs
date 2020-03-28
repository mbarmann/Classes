using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MatthewBarmann.Pages
{
    public partial class Homework2 : System.Web.UI.Page
    {
        protected void cmdSubmit_Click(object sender, EventArgs e)
        {
            if (Page.IsValid)
            {
                message.Text = "This is a valid form."; // displays message whena submitted form is valid
            }
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack)
            {
                myForm.Visible = false; //hide the form after the user submits a valid form
                myResults.Text = fName.Text + " " + lName.Text + "<br>" +
                    address.Text + "<br>" +
                    city.Text + "<br>" +
                    state.SelectedValue + "<br>" +
                    zip.Text + "<br>" +
                    number.Text + "<br>" +
                    email.Text + "<br>" +
                    username.Text + "<br>" +
                    password.Text + "<br>" +
                    date.Text + "<br>" +
                    parkAreas.SelectedValue + "<br>" +
                    travel.SelectedValue + "<br>" +
                    contactPref.SelectedValue + "<br>"; //a string that concatenates all the responses from the form into one label
            }
            else
            {
                fName.Focus();//displays the form and sets the focus to the first item
            }
        }
    }
}