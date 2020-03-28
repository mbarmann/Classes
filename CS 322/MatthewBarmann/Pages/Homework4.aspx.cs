using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MatthewBarmann.Pages
{
    public partial class Homework4 : System.Web.UI.Page
    {
        protected void submitOn_Click(object sender, EventArgs e)
        {
            submitResponse.Text = "Our weekly newsletter will now be sent to: " + email.Text; //Modify reponse label to include string & value from the textbox
        }
    }
}