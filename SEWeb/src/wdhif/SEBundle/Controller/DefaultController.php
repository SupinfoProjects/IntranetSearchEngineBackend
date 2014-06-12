<?php

namespace wdhif\SEBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;

class DefaultController extends Controller
{
    /**
     * @Route("/", name="search")
     * @Template()
     */
    public function indexAction()
    {
        return array();
    }
    /**
     * @Route("/result", name="result")
     * @Template()
     */
    public function resultAction()
    {
        $pages = array();
        $page = "toto";
        for($i=0; $i < 42; $i++){
            $pages[] = $page;
        }
        $paginator  = $this->get('knp_paginator');
        $pagination = $paginator->paginate(
            $pages,
            $this->get('request')->query->get('page', 1)/*page number*/,
            10/*limit per page*/
        );
        return array("pagination" => $pagination );
    }
}