<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Calendar.aspx.cs" Inherits="MatthewBarmann.Pages.Calender" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div>
        <asp:Calendar id="MyCalender" runat="server"
            OnSelectionChanged="MyCalendar_SelectionChanged"
            OnDayRender="MyCalendar_DayRender">
        </asp:Calendar>
        <asp:Label ID="Message" runat="server" Text="" />
    </div>
</asp:Content>
